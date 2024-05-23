#include <vector>
#include <utility>
#include "traffic_jam.h"

bool AreRoadsBalanced(std::vector<std::vector<bool>> const & road_map) {
    // ins_and_outs[i] is the {incoming, outgoing} road counts for city i
    std::vector<std::pair<int, int>> ins_and_outs(road_map.size());

    // Count the incoming and outgoing roads for every city
    for (std::size_t i = 0; i < road_map.size(); ++i) {
        for (std::size_t j = 0; j < road_map.at(i).size(); ++j) {
            if (road_map.at(i).at(j)) {
                ++ins_and_outs.at(i).second;
                ++ins_and_outs.at(j).first;
            }
        }
    }

    // Ensure the incoming and outgoing counts are equal for every city
    for (auto const & p : ins_and_outs) {
        int incoming{p.first};
        int outgoing{p.second};
        if (incoming != outgoing) {
            return false;
        }
    }
    return true;
}