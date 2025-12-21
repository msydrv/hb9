#include<string>





class Secret {
    std::string info;
    std::string pass;
public:
    Secret(const std::string& information);
    Secret(const std::string& information, const std::string &pass);

    bool lock(const std::string& passwort);

    bool unlock(const std::string& passwort);

    Secret operator+(const Secret &rhs);

    friend std::ostream& operator<<(std::ostream& o, Secret x);

    int len() const;
};

std::ostream& operator<<(std::ostream& o, Secret x);