void bubbleSort() {
    if (!head) return;

    Node* end = nullptr; // Last sorted node

    while (end != head) {
        Node* current = head;
        Node* prev = nullptr;
        Node* lastSwap = head; // To optimize

        while (current->next != end) {
            if (current->data > current->next->data) {
                swapData(current->data, current->next->data);
                lastSwap = current;
            }
            current = current->next;
        }
        end = lastSwap->next; // shrink unsorted region
    }