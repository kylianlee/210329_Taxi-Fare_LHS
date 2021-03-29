//
// Created by Kylian Lee on 2021/03/29.
//
#include <iostream>
#include <vector>

#define INF 100000000

using namespace std;

long solution (int n, int s, int a, int b, vector<vector<int>> fares);

int main() {
    vector<vector<int>> fares = {{4, 1, 10}, {3, 5, 24}, {5, 6, 2}, {3, 1, 41}, {5, 1, 24}, {4, 6, 50}, {2, 4, 66}, {2, 3, 22}, {1, 6, 25}};
//    vector<vector<int>> fares = {{5, 7, 9}, {4, 6, 4}, {3, 6, 1}, {3, 2, 3}, {2, 1, 6}};

//    int answer = solution(7, 3, 4, 1, fares);
    long answer = solution(6, 4, 6, 2, fares);

    cout << answer << endl;
    return 0;
}

long solution (int n, int s, int a, int b, vector<vector<int>> fares){
    vector<vector<long>> dist(n + 1, vector<long>(n + 1, INF));

    for(int i = 0; i < fares.size(); i++){
        dist[fares[i][0]][fares[i][1]] = fares[i][2];
        dist[fares[i][1]][fares[i][0]] = fares[i][2];
    }

//    for(int i = 1; i < n + 1; i++) {
//        for (int j = 1; j < n + 1; j++)
//            cout << dist[i][j] << " ";
//        cout << endl;
//    }

    for (int i = 1; i < n + 1; ++i) {
        dist[i][i] =0;
    }
    for(int i = 1; i < n + 1; i++){
        for(int j = 1; j < n + 1; j++){
            for(int k = 1; k < n + 1; k++){
                if(dist[j][k] > dist[j][i] + dist[i][k])
                    dist[j][k] = dist[j][i] + dist[i][k];
            }
        }
    }

    for(int i = 1; i < n + 1; i++){
        for(int j = 1; j < n + 1; j++){
            cout << dist[i][j] << " ";
        }
        cout << endl;
    }

    long answer = INF;

    for(int i = 0; i < n + 1; i++){
        if(answer > dist[s][i] + dist[i][a] + dist[i][b])
            answer = dist[s][i] + dist[i][a] + dist[i][b];
    }

    return answer;
}

