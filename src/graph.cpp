#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;

const int inf = 2e9;

struct Grafo{

    int n, m;
    int menor, maior, total;
    vector<int> grau, vis, dist, pai;
    vector<vector<int>> adj;

    Grafo(int n_) : n(n_), m(0), grau(n_+1), adj(n_+1) {}

    vector<vector<int>> components(){ // tarefa 6
        vector<vector<int>> asw;
        vis.assign(n+1, 0);
        for(int v=1; v<=n; v++){
            if(vis[v]) continue;
            vector<int> comp;
            dfs(v, comp);
            asw.push_back(comp);
        }
        sort(asw.begin(), asw.end(), [](const vector<int> &a, const vector<int> &b){
            return a.size() > b.size();
        });
        return asw;
    }

    void dfs(int v, vector<int> &c){ // tarefa 6
        vis[v] = 1;
        c.push_back(v);
        for(int prox: adj[v]){
            if(vis[prox]) continue;
            dfs(prox, c);
        }
    }

    int distancia(int u, int v){ // tarefa 5
        bfs(u);
        return dist[v];
    }

    int diametro(){ // tarefa 5
        if(is_a_tree()){
            bfs(1);
            int v1 = max_element(dist.begin()+1, dist.end()) - dist.begin();
            bfs(v1);
            int v2 = max_element(dist.begin()+1, dist.end()) - dist.begin();
            bfs(v2);
            return *max_element(dist.begin()+1, dist.end());
        }

        int asw=0;
        for(int v=1; v<=n; v++){
            bfs(v);
            asw = max(asw, *max_element(dist.begin()+1, dist.end()));
        }

        return asw;
    }

    bool is_a_tree(){
        if(m != n-1) return false;
        bfs(1);
        return *min_element(vis.begin()+1, vis.end());
    }
    
    void add_edge(int u, int v){ // tarefa 1
        adj[u].push_back(v);
        adj[v].push_back(u);
        grau[u]++; grau[v]++;
        m++;
    }

    void bfs(int start, bool print=false){ // Tarefa 4
        vis.assign(n+1, 0);
        dist.assign(n+1, 0);
        pai.assign(n+1, 0);

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
                fila.push(prox);
            }
        }

        if(!print) return;

        cout << "--------------------------------\n";
        cout << "Vetor de pais:\n";
        for(int v=1; v<=n; v++) cout << pai[v] << " "; cout << "\n";

        cout << "Vetor de profundidade:\n";
        for(int v=1; v<=n; v++) cout << dist[v] << " "; cout << "\n";
        cout << "--------------------------------\n";
    }

    void debug(){ // Tarefa 2
        cout << "--------------------------------\n";
        cout << "Numero de vertices = " << n << "\n";
        cout << "Numero de arestas  = " << m << "\n";

        vector<int> ord(grau.begin()+1, grau.end());
        sort(ord.begin(), ord.end());

        menor=n, maior=0, total=0;
        for(int v=1; v<=n; v++){
            menor = min(menor, grau[v]);
            maior = max(maior, grau[v]);
            total += grau[v];
        }

        ld mediana = (n%2) ? ord[n/2] : (ord[n/2-1] + ord[n/2])/2.0;

        cout << "Grau minimo        = " << menor << "\n";
        cout << "Grau maximo        = " << maior << "\n";
        cout << "Grau médio         = " << fixed << setprecision(5) << (ld)total/n << "\n";
        cout << "Grau mediano       = " << fixed << setprecision(2) << mediana << "\n";
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
