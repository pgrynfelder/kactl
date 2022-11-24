/**
 * Author: Jakub Bachurski
 * Date: 2020
 * License: CC0
 * Source: own work
 * Description:
 * In a binary matrix (with 0 at 1-margins) find the count of rectangles
 * of 1-bits of given size $w \times h$.
 * Usage:
	auto C = get_rect_count(A); C[w][h]
 * Time: O(nm)
 * Status: used
 */
#pragma once

vector<vector<uint>> get_rect_count(
        const vector<vector<bool>>& A) {
    const size_t m = A[0].size() - 2, n = A.size() - 2;
    vector<vector<uint>> R(n+2, vector<uint>(m+2)), D = R;
    for(size_t y = 1; y <= n; y++)
        for(size_t x = 1; x <= m; x++)
            D[y][x] = A[y][x] ? D[y-1][x] + 1 : 0;
    for(size_t y = 1; y <= n; y++) {
        struct rect { uint w, h; };
        vector<rect> S = {{0, 0}};
        for(size_t x = 1; x <= m+1; x++) {
            auto d = D[y][x]; uint e = 0;
            while(S.size() > 1 and S.back().h >= d) {
                auto [w, h] = S.back(); S.pop_back();
                auto l = max(S.back().h, d);
                e += w; R[l + 1][e]++; R[h + 1][e]--;
            }
            S.push_back({++e, d});
        }
    }
    for(size_t y=0; y<=n; y++) for(size_t x=0; x<=m; x++)
        R[y+1][x] += R[y][x];
    for(size_t t=0; t<2; t++) for(size_t y=0; y<=n+1; y++)
        for(size_t x = m+2; x --> 1; ) R[y][x-1] += R[y][x];
    return R;
}
