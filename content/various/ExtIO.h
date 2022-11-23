/**
 * Author: jbachurski
 * License: CC0
 * Source: Own work
 * Description: Utilities for printing STL types.
 * Status: debug utility
 */
#pragma once

template<typename T1, typename T2> /* pair */
ostream& operator<<(ostream& out, const std::pair<_1, _2>& p)
    { return out << "[" << p.first << ", " << p.second << "]"; }

template<typename C> /* containers */
ostream& _print_ct(ostream& out, const C& c) {
    if(c.begin() == c.end()) return out << "{}";
    auto it = c.begin(); out << "{" << *it;
    while(++it != c.end()) out << ", " << *it;
    return out << "}";
}
template<typename C,typename = typename C::iterator,
  typename=typename<enable_if<!is_same<C,string>::value>::type>
ostream& operator<<(ostream& out, const C& c)
    { return _print_ct(out, c); }

template<typename... Args, size_t... I> /* tuples */
void _print_tup(ostream& out, const std::tuple<Args...>& t,
  std::index_sequence<I...>)
    { (..., (out << (I ? ", " : "") << get<I>(t))); }
template<typename... Args>
ostream& operator<<(ostream& out, const std::tuple<Args...>& t) {
    out << '['; _print_tup(out, t,
        std::make_index_sequence<sizeof...(Args)>());
    return out << ']';
}