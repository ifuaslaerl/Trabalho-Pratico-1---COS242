#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;

const int inf = 2e9;

struct Grafo{

    int n, m;
    int menor, maior, total;
    vector<int> grau;
    vector<vector<int>> adj;

    Grafo(int n_) : n(n_+1), m(0), grau(n_+1), adj(n_+1) {}

    void add_edge(int u, int v){ // tarefa 1
        adj[u].push_back(v);
        adj[v].push_back(u);
        grau[u]++; grau[v]++;
        m++;
    }

    void bfs(int start){ // Tarefa 4
        vector<int> vis(n+1, 0), dist(n+1, 0), pai(n+1, 0);
        queue<int> fila;
        
        fila.push(start);
        vis[start] = true;
        pai[start] = start;

        while(!fila.empty()){
            int v = fila.front();
            fila.pop();

            for(int prox: adj[v]){
                if(vis[prox]) continue;
                vis[prox] = true;
                dist[prox] = dist[v] + 1;
                pai[prox] = v;
            }
        }

        cout << "--------------------------------\n";
        cout << "Vetor de pais:\n";
        for(int v=1; v<=n; v++) cout << pai[v] << " "; cout << "\n";

        cout << "Vetor de profundidade:\n";
        for(int v=1; v<=n; v++) cout << pai[v] << " "; cout << "\n";
        cout << "--------------------------------\n";
    }

    void debug(){ // Tarefa 2
        cout << "--------------------------------\n";
        cout << "Numero de vertices = " << n << "\n";
        cout << "Numero de arestas  = " << m << "\n";

        vector<int> ord = grau;
        sort(ord.begin(), ord.end());
        
        menor=n, maior=0, total=0;
        for(int v=1; v<=n; v++){
            menor = min(menor, grau[v]);
            maior = max(maior, grau[v]);
            total += grau[v];        
        }

        cout << "Grau minimo        = " << menor << "\n";
        cout << "Grau maximo        = " << maior << "\n";
        cout << "Grau médio         = " << fixed << setprecision(5) << (ld)total/n << "\n";
        cout << "Grau mediano       = " << fixed << setprecision(2) << (ld)(n%2 ? ord[n/2] : (ord[n/2] + ord[n/2+1])/2) << "\n";
        cout << "--------------------------------\n";
    }

    void conections(){ // Tarefa 3
        cout << "--------------------------------\n";
        for(int v=1; v<=n; v++){
            cout << "adjacencias de " << v << " : ";
            for(auto viz: adj[v]) cout << viz << " ";
            cout << "\n";
        }
        cout << "--------------------------------\n";
    }

};

int main(){
    return 0;
}
