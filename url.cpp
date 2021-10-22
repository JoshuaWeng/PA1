#include <iostream>
#include "version.h"
using namespace std;

int main() {
    version v = version();
    v.displayVersion();
    string url;
    getline(std::cin, url);
    //cout << "URL: " + url + "\n";

    int loc = url.find("//");

    string pro = url.substr(0,loc-1);
    url = url.substr(loc+2,-1);
    loc = url.find("/");
    string dom = url.substr(0,loc);
    string path = url.substr(dom.length(),-1);
    int port = -1;
    loc = dom.find(":");
    if(loc!=-1){
        port = stoi(dom.substr(loc+1,-1));  
        dom = dom.substr(0,loc);  
    }
    loc = path.find("?");
    string para = "N/A";
    if(loc!=-1){
        para = path.substr(loc,-1);  
        path = path.substr(0,loc);  
    }
    string valid = "";

    if(pro.compare("http") == 0 || pro.compare("https") == 0 || pro.compare("ftp") == 0 || pro.compare("ftps") == 0 ){
    }
    else{
        valid+="pro";
    }
    string valdom = dom.substr(dom.length()-3,-1);
    if(valdom.compare("com") == 0 || valdom.compare("net") == 0 || valdom.compare("edu") == 0 || valdom.compare("biz") == 0 || valdom.compare("gov") == 0){
    }
    else{
        valid+="dom";
    }
    if(port <= 65535 && (port==-1||port >=1)){
    }
    else{
        valid+="port";
    }
    if(path.find("/")==0 && (path.find(".html") == path.length()-5)|| (path.find(".htm") == path.length()-4)){
    }
    else{
        valid += "path";    
    }
    
    if(valid.length()!=0){

        cout << "\nInvalid URL with following erroneous components:\n\n";
        
        if(valid.find("pro")!=-1)
        cout << "Protocol:   " + pro + " is not a valid protocol\n";
        if(valid.find("dom")!=-1)
        cout << "Domain:     " + dom + " is an invalid domain\n";
        if(valid.find("port")!=-1)
        cout << "Port:       port number must be between 1 and 65535\n";
        if(valid.find("path")!=-1)
        cout << "Path:       " + path + " is not a valid path\n";
    }
    else{
        cout << "Protocol:   " + pro + "\n";
        cout << "Domain:     " + dom + "\n";
        cout << "Port:       ";
        if(port==-1)
        cout << "N/A";
        else
        cout << port;
        cout << "\n";
        cout << "Path:       " + path + "\n";
        cout << "Parameters: " + para + "\n";
    
    }
    return 0;
}



