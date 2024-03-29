#include <bits/stdc++.h>
#define int long long

#define pll pair<long long, long long>

#define vvi vector<vector<int>>

#define in(x)    \
    long long x; \
    cin >> x

#define pb push_back

#define F first

#define S second

#define endl "\n"

#define test() \
    int t;     \
    cin >> t;  \
    while (t--)

#define KStest() \
    int t, t1;   \
    cin >> t;    \
    t1 = t;      \
    while (t--)

#define KScout cout << "Case #" << t1 - t << ": "

#define deb(x) cout << #x << " " << x << endl;

#define setbits __builtin_popcountll

const long long mod = 1e9 + 7;

const int MAX = INT_MAX;

const long long inf = LLONG_MAX;

const double pi = 3.14159265358979323846;

int dirX[] = {1, -1, 0, 0};

int dirY[] = {0, 0, 1, -1};

using namespace std;

void print_bool(bool zeman_modnar)

{

    if (zeman_modnar)

        cout << "YES" << endl;

    else

        cout << "NO" << endl;
}

// template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// order_of_key   ==> number of elements whose value is less than the given element

// find_by_order ==> kth element in the set (counting from 0)

struct Dinic
{

    // from x to y with residual capacity

    struct edge
    {

        int x, y, w;
    };

    vector<vector<int>> gr;

    vector<edge> edges;

    vector<int> level;

    vector<int> edge_sz;

    int n, source, sink, ec = 0;

    Dinic(int n, int source, int sink)
    {

        this->n = n;

        this->source = source;

        this->sink = sink;

        gr.resize(n);

        edge_sz.resize(n);
    }

    void add_edge(int x, int y, int w)
    { // All I need to do is add edges in here

        edges.push_back({x, y, w}); // X ---> Y, of weight W

        gr[x].push_back(ec++);

        edges.push_back({y, x, 0});

        gr[y].push_back(ec++);
    }

    bool level_graph()
    {

        level.clear();
        level.resize(n, -1);

        queue<int> Q;

        Q.push(source);

        level[source] = 0;

        while (!Q.empty())
        {

            int cur = Q.front();

            Q.pop();

            for (auto xx : gr[cur])
            {

                int to = edges[xx].y;

                int w = edges[xx].w;

                if (w && level[to] == -1)
                {

                    level[to] = level[cur] + 1;

                    Q.push(to);
                }
            }
        }

        return level[sink] != -1;
    }

    int augment(int cur, int flow)
    {

        if (cur == sink)
        {

            return flow;
        }

        for (int &i = edge_sz[cur]; i >= 0; i--)
        {

            int edge_index = gr[cur][i];

            int w = edges[edge_index].w;

            int y = edges[edge_index].y;

            if (w && level[y] == level[cur] + 1)
            {

                int bottleneck_flow = augment(y, min(w, flow));

                if (bottleneck_flow)
                {

                    // forward edge according to current augmented path

                    edges[edge_index].w -= bottleneck_flow;

                    // backward edge

                    edges[edge_index ^ 1].w += bottleneck_flow;

                    return bottleneck_flow;
                }
            }
        }

        return 0;
    }

    int max_flow()
    {

        int total_flow = 0;

        while (level_graph())
        {

            // find augmenting paths and update in residual network

            for (int i = 0; i < n; i++)
                edge_sz[i] = gr[i].size() - 1;

            while (int flow = augment(source, 1e18))
            {

                total_flow += flow;
            }
        }

        return total_flow;
    }

    bool func(int curr, vector<int> &path)

    {

        path.pb(curr);

        if (curr == sink)

            return true;

        for (int &i = edge_sz[curr]; i >= 0; i--)

        {

            int edge_index = gr[curr][i];

            if (edge_index & 1) // consider only even index edges for finding actual paths as the index + 1 are back_edges(directed graph)

                continue;

            if (edges[edge_index].w == 0)

            {

                func(edges[edge_index].y, path);

                i--;

                return true;
            }
        }

        return false;
    }

    vvi get_paths()
    {

        vvi ans;

        for (int i = 0; i < n; i++)
            edge_sz[i] = gr[i].size() - 1;

        vector<int> path;

        while (func(source, path))

        {

            ans.pb(path);

            path.clear();
        }

        return ans;
    }
};

int32_t main()

{

    ios_base::sync_with_stdio(false);

    cin.tie(NULL);

#ifndef ONLINE_JUDGE

    freopen("input.txt", "r", stdin);

    freopen("output.txt", "w", stdout);

#endif

    in(n);
    in(m);

    Dinic d(n + 1, 1, n);

    for (int i = 0; i < m; i++)

    {

        in(u);
        in(v);

        d.add_edge(u, v, 1);
    }

    int ans = d.max_flow();
    cout << ans << endl;
    vvi paths = d.get_paths();
    for (auto it : paths)
    {

        cout << it.size() << endl;
        for (auto i : it)
            cout << i << " ";

        cout << endl;
    }
    return 0;
}