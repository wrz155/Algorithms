#include <iostream>

class Node {
public:
	Node(int _value) 
		:value(_value), parent(NULL), left(NULL), right(NULL) {};

	Node(int _value, Node* _parent, Node* _left, Node* _right)
		:value(_value), parent(_parent), left(_left), right(_right) {};

	int value;
	Node* parent;
	Node* left;
	Node* right;
};

class AbstractBinarySearchTree {
public:
	Node root;
protected:
	int size;/** Tree size. */

protected:
	Node* createNode(int value, Node* parent, Node* left, Node* right) {
		return new Node(value, parent, left, right);
	}

	/**
	 * Finds a node with concrete value. If it is not found then null is
	 * returned.
	 * 
	 * @param element
	 *            Element value.
	 * @return Node with value provided, or null if not found.
	 */
public:
	Node* search(int element) {
		Node node = root;
		while (NULL != node && node.value != null && node.value != element) {
			if (element < node.value) {
				node = node.left;
			} else {
				node = node.right;
			}
		}
		return node;
	}

	/**
	 * Insert new element to tree.
	 * 
	 * @param element
	 *            Element to insert.
	 */
	public Node insert(int element) {
		if (root == null) {
			root = createNode(element, null, null, null);
			size++;
			return root;
		}

		Node insertParentNode = null;
		Node searchTempNode = root;
		while (searchTempNode != null && searchTempNode.value != null) {
			insertParentNode = searchTempNode;
			if (element < searchTempNode.value) {
				searchTempNode = searchTempNode.left;
			} else {
				searchTempNode = searchTempNode.right;
			}
		}

		Node newNode = createNode(element, insertParentNode, null, null);
		if (insertParentNode.value > newNode.value) {
			insertParentNode.left = newNode;
		} else {
			insertParentNode.right = newNode;
		}

		size++;
		return newNode;
	}

	/**
	 * Removes element if node with such value exists.
	 * 
	 * @param element
	 *            Element value to remove.
	 * 
	 * @return New node that is in place of deleted node. Or null if element for
	 *         delete was not found.
	 */
	public Node delete(int element) {
		Node deleteNode = search(element);
		if (deleteNode != null) {
			return delete(deleteNode);
		} else {
			return null;
		}
	}

	/**
	 * Delete logic when node is already found.
	 * 
	 * @param deleteNode
	 *            Node that needs to be deleted.
	 * 
	 * @return New node that is in place of deleted node. Or null if element for
	 *         delete was not found.
	 */
	protected Node delete(Node deleteNode) {
		if (deleteNode != null) {
			Node nodeToReturn = null;
			if (deleteNode != null) {
				if (deleteNode.left == null) {
					nodeToReturn = transplant(deleteNode, deleteNode.right);
				} else if (deleteNode.right == null) {
					nodeToReturn = transplant(deleteNode, deleteNode.left);
				} else {
					Node successorNode = getMinimum(deleteNode.right);
					if (successorNode.parent != deleteNode) {
						transplant(successorNode, successorNode.right);
						successorNode.right = deleteNode.right;
						successorNode.right.parent = successorNode;
					}
					transplant(deleteNode, successorNode);
					successorNode.left = deleteNode.left;
					successorNode.left.parent = successorNode;
					nodeToReturn = successorNode;
				}
				size--;
			}

			return nodeToReturn;
		}
		return null;
	}

	/**
	 * Put one node from tree (newNode) to the place of another (nodeToReplace).
	 * 
	 * @param nodeToReplace
	 *            Node which is replaced by newNode and removed from tree.
	 * @param newNode
	 *            New node.
	 * 
	 * @return New replaced node.
	 */
	private Node transplant(Node nodeToReplace, Node newNode) {
		if (nodeToReplace.parent == null) {
			this.root = newNode;
		} else if (nodeToReplace == nodeToReplace.parent.left) {
			nodeToReplace.parent.left = newNode;
		} else {
			nodeToReplace.parent.right = newNode;
		}
		if (newNode != null) {
			newNode.parent = nodeToReplace.parent;
		}
		return newNode;
	}

	/**
	 * @param element
	 * @return true if tree contains element.
	 */
	public boolean contains(int element) {
		return search(element) != null;
	}

	/**
	 * @return Minimum element in tree.
	 */
	public int getMinimum() {
		return getMinimum(root).value;
	}

	/**
	 * @return Maximum element in tree.
	 */
	public int getMaximum() {
		return getMaximum(root).value;
	}

	/**
	 * Get next element element who is bigger than provided element.
	 * 
	 * @param element
	 *            Element for whom descendand element is searched
	 * @return Successor value.
	 */
	// TODO Predecessor
	public int getSuccessor(int element) {
		return getSuccessor(search(element)).value;
	}

	/**
	 * @return Number of elements in the tree.
	 */
	public int getSize() {
		return size;
	}

	/**
	 * Tree traversal with printing element values. In order method.
	 */
	public void printTreeInOrder() {
		printTreeInOrder(root);
	}

	/**
	 * Tree traversal with printing element values. Pre order method.
	 */
	public void printTreePreOrder() {
		printTreePreOrder(root);
	}

	/**
	 * Tree traversal with printing element values. Post order method.
	 */
	public void printTreePostOrder() {
		printTreePostOrder(root);
	}

	/*-------------------PRIVATE HELPER METHODS-------------------*/

	private void printTreeInOrder(Node entry) {
		if (entry != null) {
			printTreeInOrder(entry.left);
			if (entry.value != null) {
				System.out.println(entry.value);
			}
			printTreeInOrder(entry.right);
		}
	}

	private void printTreePreOrder(Node entry) {
		if (entry != null) {
			if (entry.value != null) {
				System.out.println(entry.value);
			}
			printTreeInOrder(entry.left);
			printTreeInOrder(entry.right);
		}
	}

	private void printTreePostOrder(Node entry) {
		if (entry != null) {
			printTreeInOrder(entry.left);
			printTreeInOrder(entry.right);
			if (entry.value != null) {
				System.out.println(entry.value);
			}
		}
	}

	protected Node getMinimum(Node node) {
		while (node.left != null) {
			node = node.left;
		}
		return node;
	}

	protected Node getMaximum(Node node) {
		while (node.right != null) {
			node = node.right;
		}
		return node;
	}

	protected Node getSuccessor(Node node) {
		// if there is right branch, then successor is leftmost node of that
		// subtree
		if (node.right != null) {
			return getMinimum(node.right);
		} else { // otherwise it is a lowest ancestor whose left child is also
			// ancestor of node
			Node currentNode = node;
			Node parentNode = node.parent;
			while (parentNode != null && currentNode == parentNode.right) {
				// go up until we find parent that currentNode is not in right
				// subtree.
				currentNode = parentNode;
				parentNode = parentNode.parent;
			}
			return parentNode;
		}
	}

	// -------------------------------- TREE PRINTING
	// ------------------------------------

	public void printTree() {
		printSubtree(root);
	}

	public void printSubtree(Node node) {
		if (node.right != null) {
			printTree(node.right, true, "");
		}
		printNodeValue(node);
		if (node.left != null) {
			printTree(node.left, false, "");
		}
	}

	private void printNodeValue(Node node) {
		if (node.value == null) {
			System.out.print("<null>");
		} else {
			System.out.print(node.value.toString());
		}
		System.out.println();
	}

	private void printTree(Node node, boolean isRight, String indent) {
		if (node.right != null) {
			printTree(node.right, true, indent + (isRight ? "        " : " |      "));
		}
		System.out.print(indent);
		if (isRight) {
			System.out.print(" /");
		} else {
			System.out.print(" \\");
		}
		System.out.print("----- ");
		printNodeValue(node);
		if (node.left != null) {
			printTree(node.left, false, indent + (isRight ? " |      " : "        "));
		}
	}


}
