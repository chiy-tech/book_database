

#include <string>
#include <vector>

using namespace std;


class bookDatabase{
public:

  virtual vector<string>  Title();

  virtual vector<string>  Author();


  virtual vector<int>  Date();

  virtual vector<string>  Booktype();

  virtual vector<string>  ISBN();
 
    virtual vector<int>  NumOfPages();



  // virtual destructor
  virtual ~bookDatabase() { }






};