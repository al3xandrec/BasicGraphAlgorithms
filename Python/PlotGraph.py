import matplotlib.pyplot as plt
import networkx as nx

# Aprender saporra. :D

def PlotGraph(n, adjMatrix):
    G = nx.MultiDiGraph()

    for i in range(n):
        for j in range(n):
            G.add_edge(i, j, weight=adjMatrix[i][j])

    # Manually define the layout for the graph (absolute positions)
    pos = {0: (0, 0), 1: (1, 0), 2: (0.5, 1)}

    # Variables to store dragging state
    dragging = False
    dragged_node = None
    scale = 1.0

    # Draw the graph
    def draw_graph():
        plt.clf()  # Clear the current figure
        nx.draw(G, pos, with_labels=True, node_color='skyblue', node_size=1000, font_size=20, font_weight='bold', arrows=True)
        edge_labels = nx.get_edge_attributes(G, 'weight')
        nx.draw_networkx_edge_labels(G, pos, edge_labels=edge_labels, font_color='red', font_size=20)
        plt.title('Graph Plot')
        plt.xlim(-1, 2)
        plt.ylim(-1, 2)
        plt.draw()

    # Create the plot
    fig = plt.figure(figsize=(8, 6))

    # Set the event handlers
    def on_press(event):
        nonlocal dragging, dragged_node
        if event.inaxes:
            x, y = event.xdata, event.ydata
            for node, (px, py) in pos.items():
                if (px - x) ** 2 + (py - y) ** 2 < 0.01:  # Check if the click is near a node
                    dragging = True
                    dragged_node = node
                    break

    def on_motion(event):
        nonlocal dragging, dragged_node
        if dragging and event.inaxes:
            x, y = event.xdata, event.ydata
            pos[dragged_node] = (x, y)
            draw_graph()

    def on_release(event):
        nonlocal dragging, dragged_node
        dragging = False
        dragged_node = None

    def on_scroll(event):
        nonlocal scale
        if event.inaxes:
            if event.button == 'up':
                scale *= 1.1
            elif event.button == 'down':
                scale /= 1.1
            for node in pos:
                pos[node] = (pos[node][0] * scale, pos[node][1] * scale)
            draw_graph()

    # Connect the event handlers to the figure
    fig.canvas.mpl_connect('button_press_event', on_press)
    fig.canvas.mpl_connect('motion_notify_event', on_motion)
    fig.canvas.mpl_connect('button_release_event', on_release)
    fig.canvas.mpl_connect('scroll_event', on_scroll)

    # Initial drawing
    draw_graph()

    # Show the plot
    plt.show()
