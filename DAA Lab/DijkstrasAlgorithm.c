#include <stdio.h>
#include <limits.h>

#define MAX 10
#define INF 9999

void dijkstras(int graph[MAX][MAX], int n, int src)
{
      int distance[MAX], visited[MAX];
      int count, minDistance, nextNode;

      for (int i = 0; i < n; i++)
      {
            distance[i] = graph[src][i];
            visited[i] = 0;
      }

      distance[src] = 0;
      visited[src] = 1;

      for (count = 1; count < n; count++)
      {
            minDistance = INF;

            for (int i = 0; i < n; i++)
            {
                  if (!visited[i] && distance[i] < minDistance)
                  {
                        minDistance = distance[i];
                        nextNode = i;
                  }
            }

            visited[nextNode] = 1;

            for (int i = 0; i < n; i++)
            {
                  if (!visited[i] && graph[nextNode][i] != INF &&
                      distance[nextNode] + graph[nextNode][i] < distance[i])
                  {
                        distance[i] = distance[nextNode] + graph[nextNode][i];
                  }
            }
      }

      printf("\nShortest distances from source (%d):\n", src);
      for (int i = 0; i < n; i++)
      {
            printf("To node %d = %d\n", i, distance[i]);
      }
}

int main()
{
      int n, i, j, src;

      int graph[MAX][MAX];

      printf("Enter number of nodes: ");
      scanf("%d", &n);

      printf("Enter adjacency matrix (enter 9999 for no edge): \n");
      for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                  scanf("%d", &graph[i][j]);
            }
      }

      printf("Enter source node: ");
      scanf("%d",&src);

      dijkstras(graph, n, src);
      
      return 0;
}
