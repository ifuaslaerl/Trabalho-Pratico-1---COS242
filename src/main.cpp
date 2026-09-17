#include "graph.cpp"

// Formato de entrada:
//   linha 1 : n (numero de vertices)
//   linhas seguintes : "u v" (uma aresta por linha) ate o fim do arquivo
//
// Uso:
//   g++ -O2 -std=c++17 main.cpp -o a.out
//   ./a.out < in_file > out_file

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    Grafo g(n);

    int u, v;
    while(cin >> u >> v) g.add_edge(u, v);

    g.debug();
    g.conections();

    cout << "Componentes conexas (da maior para a menor):\n";
    auto comps = g.components();
    cout << "--------------------------------\n";
    cout << "Numero de componentes = " << comps.size() << "\n";
    for(size_t i = 0; i < comps.size(); i++){
        cout << "Componente " << i+1 << " (tamanho " << comps[i].size() << "): ";
        for(int vertice: comps[i]) cout << vertice << " ";
        cout << "\n";
    }
    cout << "--------------------------------\n";

    cout << "BFS a partir do vertice 1:\n";
    g.bfs(1, true);

    cout << "Diametro = " << g.diametro() << "\n";

    return 0;
}
