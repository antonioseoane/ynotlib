#include <ynsystem\System.h>

using namespace ynsystem;

/*
 *
 */
extern std::string get_env_var( std::string const & key ) 
{                                 
  char * val;                                                                        
  val = getenv( key.c_str() );                                                       
  std::string retval = "";                                                           
  if (val != NULL) {                                                                 
    retval = val;                                                                    
  }                                                                                  
  return retval;                                                                        
}
