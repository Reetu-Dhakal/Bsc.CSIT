# --- Minimax Algorithm Function ---
def minimax(depth, node_index, is_maximizing_player, values, max_depth):

    # Base case: If we have reached the maximum depth (a leaf node), return its value.
    if depth == max_depth:
        return values[node_index]

    # Maximizing player's turn
    if is_maximizing_player:
        # Recursively get the scores from the left and right children
        left_score = minimax(depth + 1, node_index * 2, False, values, max_depth)
        right_score = minimax(depth + 1, node_index * 2 + 1, False, values, max_depth)
        
        # Return the maximum of the two scores
        return max(left_score, right_score)
    else:  # Minimizing player's turn
        # Recursively get the scores from the left and right children
        left_score = minimax(depth + 1, node_index * 2, True, values, max_depth)
        right_score = minimax(depth + 1, node_index * 2 + 1, True, values, max_depth)
        
        # Return the minimum of the two scores
        return min(left_score, right_score)

# --- Main Program ---
if __name__ == "__main__":
    # The scores at the leaf nodes of the game tree
    # The number of values must be a power of 2 for a complete binary tree
    values = [3, 5, 4, 9]
    
    # The maximum depth of the tree (number of levels from root to leaves)
    # A tree with 4 leaf nodes has a max_depth of 2
    max_depth = 2

    # Start the Minimax algorithm from the root node (depth 0, index 0)
    # The first player is the maximizing player
    optimal_value = minimax(0, 0, True, values, max_depth)

    # Display the result
    print("The optimal value is:", optimal_value)