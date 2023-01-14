#include <iostream>
#include <string>
#include <memory>

using namespace std;

class Searcher{
public:
    virtual string doSearch() = 0;
};

class AccessValidator{
public:
    bool validate(){
        cout << "Access Validator validate\n";
    };
};

class Logger{
public:
    void log() {
        cout << "Logger log\n";
    }
};

class RealSearch:public Searcher{
public:
    string doSearch(){
        cout << "real search search\n";
    }
};

class ProxySearch:public Searcher{
public:

    ProxySearch(shared_ptr<Searcher> realsearch_, shared_ptr<AccessValidator> validator_, shared_ptr<Logger> logger_){
        validator = validator_;
        logger = logger_;
        searcher = realsearch_;
    }

    string doSearch(){
        validate();
        searcher->doSearch();
        log();
    }

    bool validate(){
        validator->validate();
    }
    void log(){
        logger->log();
    }

private:
    shared_ptr<AccessValidator> validator;
    shared_ptr<Logger> logger;
    shared_ptr<Searcher> searcher;
};

int main(){
    shared_ptr<Searcher> searcher(new RealSearch());
    shared_ptr<AccessValidator> validator(new AccessValidator());
    shared_ptr<Logger> logger(new Logger());

    ProxySearch * proxySearch = new ProxySearch(searcher, validator, logger);
    proxySearch->doSearch();
}