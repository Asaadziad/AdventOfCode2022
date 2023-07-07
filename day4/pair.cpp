#include "pair.h"




Pair::Pair(std::string assignment){
    int i = assignment.find(",");
    std::string first = assignment.substr(0,i);
    std::string second = assignment.substr(i+1);

    first_section = Section(first);
    second_section = Section(second);

}

bool Pair::isSectionsOverlaped(){
    return (first_section < second_section) || 
    (second_section < first_section);
}

bool Pair::isSectionParlyOverlaped(){
    return (first_section <= second_section) ||
    (second_section <= first_section);
}