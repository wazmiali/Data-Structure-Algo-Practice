#include<stdio.h>

#define MAX 20

struct edges {
    int u, v, w;
};

// Find parent (Path compression)
int findParent(int parent[], int x) {
    if (parent[x] == x)
        return x;
    return parent[x] = findParent(parent, parent[x]);
}

// Union of two sets
void unionSet(int parent[], int a, int b) {
    int pA = findParent(parent, a);
    int pB = findParent(parent, b);
    parent[pA] = pB;
}

int main() {
    int n, e;
    struct edges edgeList[MAX], mst[MAX];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &e);

    printf("Enter edges (u v w):\n");
    for (int i = 0; i < e; i++) {
        scanf("%d %d %d", &edgeList[i].u, &edgeList[i].v, &edgeList[i].w);
    }

    // Sort edges by weight
    for (int i = 0; i < e - 1; i++) {
        for (int j = 0; j < e - i - 1; j++) {
            if (edgeList[j].w > edgeList[j + 1].w) {
                struct edges temp = edgeList[j];
                edgeList[j] = edgeList[j + 1];
                edgeList[j + 1] = temp;
            }
        }
    }

    int parent[MAX];
    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }

    int count = 0, totalWeight = 0;

    // Kruskal's Algorithm
    for (int i = 0; i < e; i++) {
        int p1 = findParent(parent, edgeList[i].u);
        int p2 = findParent(parent, edgeList[i].v);

        if (p1 != p2) { // no cycle
            mst[count++] = edgeList[i];
            totalWeight += edgeList[i].w;
            unionSet(parent, p1, p2);
        }

        if (count == n - 1)
            break;
    }

    printf("\nMinimum Spanning Tree:\n");
    for (int i = 0; i < count; i++) {
        printf("%d -- %d (Weight = %d)\n", mst[i].u, mst[i].v, mst[i].w);
    }

    printf("\nTotal Weight of MST = %d\n", totalWeight);

    return 0;
}