import networkx as nx
import matplotlib.pyplot as plt

def create_semantic_network():
    """
    Creates and visualizes a semantic network based on a set of facts.
    """

    # Step 1: Create a directed graph
    G = nx.DiGraph()

    # Step 2: Define entities (nodes)
    ENTITIES = [
        "Election 2025", "John Smith", "Democratic Party", "New York",
        "Jane Miller", "Republican Party", "Debate Event", "News Channel"
    ]

    G.add_nodes_from(ENTITIES)

    # Step 3: Define relationships (edges)
    RELATIONSHIPS = [
        ("John Smith", "Election 2025", "is a candidate in"),
        ("Jane Miller", "Election 2025", "is a candidate in"),
        ("John Smith", "Democratic Party", "is a member of"),
        ("Jane Miller", "Republican Party", "is a member of"),
        ("Debate Event", "Election 2025", "is part of"),
        ("John Smith", "Debate Event", "participated in"),
        ("Jane Miller", "Debate Event", "participated in"),
        ("News Channel", "Debate Event", "reported on"),
        ("Election 2025", "New York", "is held in")
    ]

    for src, tgt, rel in RELATIONSHIPS:
        G.add_edge(src, tgt, relation=rel)

    # Step 4: Generate readable summary
    def generate_sentences(graph):
        sentences = []
        for src, dst, data in graph.edges(data=True):
            sentence = f"{src} {data['relation']} {dst}."
            sentences.append(sentence)
        return sentences

    print("📰 News Summary based on Semantic Network:\n")
    for sentence in generate_sentences(G):
        print("•", sentence)

    print("\n" + "=" * 60 + "\n")

    # Step 5: Visualization
    plt.figure(figsize=(12, 9))
    
    # Use spring layout with fixed seed for consistency
    pos = nx.spring_layout(G, seed=42, k=1.2)

    # Draw nodes
    nx.draw_networkx_nodes(G, pos,
                           node_color="#A0CBE2",
                           node_size=2200,
                           edgecolors="black",
                           linewidths=1.5)

    # Draw node labels
    nx.draw_networkx_labels(G, pos,
                            font_size=10,
                            font_weight="bold")

    # Draw edges
    nx.draw_networkx_edges(G, pos,
                           edge_color="gray",
                           arrows=True,
                           arrowsize=20,
                           width=2)

    # Draw edge labels (relationship text)
    edge_labels = nx.get_edge_attributes(G, 'relation')
    nx.draw_networkx_edge_labels(G, pos,
                                 edge_labels=edge_labels,
                                 font_color="darkred",
                                 font_size=9,
                                 label_pos=0.5)

    # Add a title
    plt.title("📊 Semantic Network of Political News", fontsize=14, fontweight="bold", pad=20)

    # Remove axis for cleaner look
    plt.axis('off')
    plt.tight_layout()
    plt.show()


# Run the program
create_semantic_network()
