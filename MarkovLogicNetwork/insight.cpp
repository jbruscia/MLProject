//implementation for the insight class
//Michael Krumdick

#include "insight.h"
   
insight::insight(int len, string in) : identifier(in), ocur(0), verif(0), attempts(0), successes(0), failures(0), length(len){
    std::random_device rd;
    std::default_random_engine gen(rd());
    std::uniform_int_distribution<int> d(0,1);
    std::uniform_int_distribution<int> d1(0, len);
    order.push_back(d1(gen));
    compOrder.push_back(d(gen));
    std::normal_distribution<double> dist(0.0, 1.0);
    constants.push_back( 1 - dist(gen));
    vectorInit();
}

void insight::reset(){
    attempts    = 0;
    successes   = 0;
    failures    = 0;
    verif       = 0;
    ocur        = 0;
}

double insight::weight() const{
    //Bayes
    if (attempts > 0){
        return verif/(1 + ocur)*successes/(attempts*(1.0 + verif - successes));
    } else {
        return 0.0;
    }
}

void insight::check(node n) {
    bool final = comparisions[compOrder[0]](n[order[0]], constants[0]);
    for(int i = 1; i < order.size(); i++){
        if (connectOrder[i] == 0){
            final = final || comparisions[compOrder[i]](n[order[i]], constants[i]);
        } else {
            if(final){
                final = comparisions[compOrder[i]](n[order[i]], constants[i]);
            } else {
                break;
           }
        }
    }
//this is overly verbose, but deal with it    
    attempts++;
    if(identifier.compare(n.getIdent()) == 0){
        ocur++;
    }
    if(final){
        if(final && identifier.compare(n.getIdent()) == 0){
            successes++;
        }
        verif++;
    }
}

bool insight::evaluate(node n) {
    bool final = comparisions[compOrder[0]](n[order[0]], constants[0]);
    for(int i = 1; i < order.size(); i++){
        if (connectOrder[i] == 0){
            final = final || comparisions[compOrder[i]](n[order[i]], constants[i]);
        } else {
            if(final){
                final = comparisions[compOrder[i]](n[order[i]], constants[i]);
            } else {
                break;
           }
        }
    }
    return final;
}

void insight::vectorInit(){
    comparisions.push_back(std::greater<double>());
    comparisions.push_back(std::less<double>());
    connectors.push_back(std::logical_and<bool>());
    connectors.push_back(std::logical_or<bool>());

}

string insight::ident() const {
    return identifier;
}

int insight::column() const {
    return order[0];
}

int insight::size() const {
    return length;
}

ostream& operator<<(ostream & os, insight in){
    vector<string> comp {">", "<"};
    vector<string> con {"and", "or"};
    for(int i = 0; i < in.order.size(); i++){
        os << "( Data[" << in.order[i] << "] " << comp[in.compOrder[i]] << " " << in.constants[i] << " ) ";
        if(in.connectOrder.size() > 0 && i < in.order.size() - 1) {
            os << con[in.connectOrder[i]] << " ";
        }
    }
    return os;
}
