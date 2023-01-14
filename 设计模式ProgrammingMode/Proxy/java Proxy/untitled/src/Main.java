public class Main {
    public static void main(String[] args) {

        System.out.println("Hello world!");
        AccessValidator validator = new AccessValidator();
        Logger logger = new Logger();
        Searcher searcher = new RealSearch();
        ProxySearch proxy = new ProxySearch(validator, logger, searcher);
        proxy.doSearch();
    }
}

abstract class Searcher{
    public abstract void doSearch();
}

class AccessValidator{
    public void validate(){
        System.out.println("Access Validator validate");
//        return false;
    };
}

class Logger{
    public void log(){
        System.out.println("Logger log");
    }
}

class RealSearch extends Searcher{
    public void doSearch(){
        System.out.println("Real search ");
    }
}

class ProxySearch extends Searcher{
    public void doSearch(){
        validate();
        searcher.doSearch();
        log();
    }
    private AccessValidator validator;
    private Logger logger;
    private Searcher searcher;

    public ProxySearch(AccessValidator validator_, Logger logger_, Searcher searcher_){
        validator = validator_;
        logger = logger_;
        searcher = searcher_;
    }

    public void validate(){
        validator.validate();
    }
    public void log(){
        logger.log();
    }
}