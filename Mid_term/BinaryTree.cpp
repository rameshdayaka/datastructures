# Define a class for the nodes in the binary tree
class TreeNode:
    def __init__(self, data):
        self.data = data  # Initialize the node with data
        self.left = None  # Initialize left child as None
        self.right = None  # Initialize right child as None

# Function to insert data into the binary tree
def insert(root, data):
    # If the root is empty, create a new node and return it
    if root is None:
        return TreeNode(data)
    else:
        # If the left child is empty, insert data there
        if root.left is None:
            root.left = insert(root.left, data)
        # If the left child is occupied, insert data to the right
        elif root.right is None:
            root.right = insert(root.right, data)
        else:
            # If both left and right children are occupied, go deeper
            root.left = insert(root.left, data)
    return root

# Function to print the binary tree in a hierarchical manner
def print_tree(root, level=0):
    # Print the right subtree with increased indentation
    if root is not None:
        print_tree(root.right, level + 1)
        # Print the current node's data with proper indentation
        print(' ' * 4 * level + '->', root.data)
        # Print the left subtree with increased indentation
        print_tree(root.left, level + 1)

# Function to create the cashier line represented as a binary tree
def create_cashier_line(size):
    root = None  # Initialize the root of the binary tree
    # Iterate over the number of customers in the cashier line
    for i in range(size):
        # Take input for each customer and insert them into the binary tree
        data = input("Enter data for customer {}: ".format(i + 1))
        root = insert(root, data)  # Insert the customer into the binary tree
    return root  # Return the root of the binary tree representing the cashier line

# Main part of the program
if __name__ == "__main__":
    # Take user input for the number of customers in the cashier line
    size = int(input("Enter the number of customers in the cashier line: "))
    # Create the binary tree representing the cashier line
    cashier_line = create_cashier_line(size)
    # Print the binary tree representation of the cashier line
    print("\nCashier Line (Binary Tree Representation):")
    print_tree(cashier_line)  # Call the print_tree function to print the binary tree
