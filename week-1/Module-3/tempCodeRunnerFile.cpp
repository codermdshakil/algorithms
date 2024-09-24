
    int si, sj;
    cin >> si >> sj;

    memset(visit, false, sizeof(visit));
    memset(dis, -1, sizeof(dis));
    
    bfs(si, sj);