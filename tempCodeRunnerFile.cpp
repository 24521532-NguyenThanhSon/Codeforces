<<<<<<< HEAD
void bfs(long lim){
//     memset(trace, 0, sizeof(trace));
//     queue<int> Q;
//     Q.push(0);
//     trace[0] = -1;
//     while(!Q.empty()){
//         long u = Q.front();
//         Q.pop();
//         for(long j = 0; j < adj[u].size(); j++){
//             long v = adj[u][j];
//             if(trace[v])    continue;
//             if(f[u][v] == c[u][v])  continue;
//             if(max(g[u][v], g[v][u]) > lim) continue;
//             trace[v] = u;
//             Q.push(v);
//         }
//     }
// }
// void inFlow(){
//     long delta = 1e9 + 7;
//     long v = t;
//     while(v != s){
//         long u = trace[v];
//         delta = min(delta, c[u][v] - f[u][v]);
//         v = u;
//     }
//     v = t;
//     while(v != s){
//         long u = trace[v];
//         f[u][v] += delta;
//         f[u][v] -= delta;
//     }
//     MaxFlow += delta;
// }
=======

    dp[0][0] = 1;       
    
    for(long mask = 0; mask < (1 << N) - 1; mask++)
    for(long last = 1; last <= N; last++){
        if(mask == 0)   dp[mask + (1 << (last - 1))][last] += dp[mask][0];
        else{
>>>>>>> a339e49 (up)
