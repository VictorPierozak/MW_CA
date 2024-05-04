#include<algorithm>
#include"Domain.hpp"
#include"Rules.hpp"

m_int MostNumerous::state(const std::vector<m_int>& neighbours) const
{
    m_int ssx;
    auto identity = [&ssx](const std::pair<m_int, m_int>& tt){ return tt.first == ssx;};
    std::vector<std::pair<m_int, m_int>> unique_states;
    for(m_int ss: neighbours)
    {
        ssx = ss;
        auto vptr = std::find_if(unique_states.begin(), unique_states.end(), identity);
        if(vptr != unique_states.end()) { vptr->second++;}
        else if(ss != Domain::Void) unique_states.push_back({ss, 1});
    }
    auto compare = [](const std::pair<m_int, m_int>& a, const std::pair<m_int, m_int>& b) { return a.second < b.second; };
    auto max = std::max_element(unique_states.begin(), unique_states.end(), compare);
    if(max == unique_states.end()) return Domain::Void;
    return max->first;
}

m_int LeastNumerous::state(const std::vector<m_int>& neighbours) const
{
    m_int ssx;
    auto identity = [&ssx](const std::pair<m_int, m_int>& tt){ return tt.first == ssx;};
    std::vector<std::pair<m_int, m_int>> unique_states;
    for(m_int ss: neighbours)
    {
        ssx = ss;
        auto vptr = std::find_if(unique_states.begin(), unique_states.end(), identity);
        if(vptr != unique_states.end()) { vptr->second++;}
        else if(ss != Domain::Void) unique_states.push_back({ss, 1});
    }
    auto compare = [](const std::pair<m_int, m_int>& a, const std::pair<m_int, m_int>& b) { return a.second < b.second; };
    auto min = std::min_element(unique_states.begin(), unique_states.end(), compare);
    if(min == unique_states.end()) return Domain::Void;
    return min->first;
}

std::shared_ptr<Rule> duplicate(const std::shared_ptr<Rule> &rule)
{
    std::shared_ptr<Rule> result;
    switch(rule->type())
    {
        case Rule::Type::MostNumerous:
            result.reset(new MostNumerous(*((MostNumerous*) rule.get())));
            break;
        case Rule::Type::LeastNumerous:
            result.reset(new LeastNumerous(*(LeastNumerous*) rule.get()));
            break;
    }
    return result;
}