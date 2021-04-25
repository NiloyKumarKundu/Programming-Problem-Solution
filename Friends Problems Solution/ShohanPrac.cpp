#include <stdio.h>
int main() {
	int node_number, edge_number, a, b;
	printf("Graph Input\n");
	printf("How many node in your graph?\n");
	scanf("%d", &node_number);

	int matrix[node_number][node_number];

	for (int i = 0; i < node_number; i++) {
		for (int j = 0; j < node_number; j++) {
			matrix[i][j] = 0;
		}
	}

	printf("How many edge in your graph?\n");
	scanf("%d", &edge_number);
	printf("Enter %d edge...[Example: 0 {starting_node} 1 {ending_node}]:\n", edge_number);
	for (int i = 0; i < edge_number; i++) {
		scanf("%d %d", &a, &b);
		matrix[a][b] = 1;
		matrix[b][a] = 1;
	}

	printf("Here is your graph as adjacency matrix ...\n\n");
	for (int i = 0; i < node_number; i++) {
		printf("|");
		for (int j = 0; j < node_number; j++) {
			printf("%d ", matrix[i][j]);
		}
		printf("| \n");
	}
	return 0;
}
