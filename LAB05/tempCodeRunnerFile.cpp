void DelNode(struct studentNode ***now) {
  // Check if the current node is the start of the list
  if (&(**now == start)) {
    // Update the start pointer to point to the next node in the list
    start = (**now)->next;
  } else {
    // Iterate through the list to find the node before the current node
    struct studentNode;
  }
}