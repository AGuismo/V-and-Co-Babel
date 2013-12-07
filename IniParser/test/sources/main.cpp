#include	<iostream>
#include	"IniParser.hh"

/*

  Sentence ::=	[[Blank]* Word]+ ['!'|'.'|'?']?

  Word ::=	['a'..'z' | 'A'..'Z']+

  Blank ::=	[' ' | 'TAB']

*/

/* INI

   File ::= Section*

   Section ::= SectionName Content

   SectionName ::= '[' identifier ']'

   Content ::= KeyVal*

   KeyVal ::= Key "=" Value

   Key ::= identifier

   Value ::= identifier | integer

 */

int			main(int ac, char *av[])
{
  parser::Ini		ini;

  if (ac != 2)
    {
      std::cerr << "You must specify an ini file" << std::endl;
      return (0);
    }
  if (!ini.loadFile(av[1]))
    {
      std::cerr << "Unable to load file: " << av[1] << std::endl;
      return (0);
    }
  ini.addKey("user", "name");
  ini.addKey("user", "password");
  ini.addKey("user", "age");
  ini.addKey("user", "birthday");

  ini.addKey("server", "TCPport");
  ini.addKey("server", "UDPport");
  ini.addKey("server", "ip");

  if (ini.run())
    std::cout << "My Ini file is correct" << std::endl;
  else
    std::cout << "My Ini file is not correct" << std::endl;
  return (0);
}
