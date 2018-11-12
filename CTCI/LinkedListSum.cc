Node sumLinked(Node a, Node b, int carry) {
	if ((a == null) && (b == null)) {
		return null;
	}
	int sum = carry;
	if (a != null) {
		sum += a.val;
	}
	if (b != null) {
		sum += b.val;
	}
	Node n = (sum % 10, sumLinked(a.next, b.next, sum / 10);
	return n;
}