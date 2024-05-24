#!/usr/bin/bash

GREEN='\033[0;32m'
BLUE='\033[0;34m'
RED='\033[0;31m'
NC='\033[0m'

echo
echo -e ${GREEN}'#0 Setup the infile.txt'${NC}
echo '$ echo -e '\''banana\napple\nbanana\napple\ncherry'\'' > infile.txt'
echo -e 'banana\napple\nbanana\napple\ncherry' > infile.txt
echo '$ cat infile.txt'
cat infile.txt

echo
echo -e ${GREEN}'#1 Pipex'${NC}
echo '$ ./pipex_bonus infile.txt sort "echo '\''banana\napple\ncherry'\''" sort uniq outfile.txt'
./pipex_bonus infile.txt sort "echo 'banana\napple\ncherry'" sort uniq outfile.txt
echo '$ cat outfile.txt'
cat outfile.txt
echo -e ${BLUE}'#1 Bash (which mandates the -e)'${NC}
echo '$ < infile.txt sort | echo -e '\''banana\napple\ncherry'\'' | sort | uniq > outfile.txt'
< infile.txt sort | echo -e 'banana\napple\ncherry' | sort | uniq > outfile.txt
echo '$ cat outfile.txt'
cat outfile.txt
echo -e ${BLUE}'#1 Pipex with -e'${NC}
echo '$ ./pipex_bonus infile.txt sort "echo -e '\''banana\napple\ncherry'\''" sort uniq outfile.txt'
./pipex_bonus infile.txt sort "echo -e 'banana\napple\ncherry'" sort uniq outfile.txt
echo '$ cat outfile.txt'
cat outfile.txt
echo '### Conclusion of #1: my pipex doesn'\''t tokenize. Should it?'

echo
echo -e ${GREEN}'#2 Pipex'${NC}
echo '$ ./pipex_bonus infile.txt cat sort uniq outfile.txt'
./pipex_bonus infile.txt cat sort uniq outfile.txt
echo '$ cat outfile.txt'
cat outfile.txt
echo -e ${BLUE}#2 Bash${NC}
echo '$ < infile.txt cat | sort | uniq > outfile.txt'
< infile.txt cat | sort | uniq > outfile.txt
echo '$ cat outfile.txt'
cat outfile.txt

echo
echo -e ${GREEN}'#3 Pipex'${NC}
echo '$ ./pipex_bonus infile.txt cat bbbb sort outfile.txt'
./pipex_bonus infile.txt cat bbbb sort outfile.txt
echo -e ${BLUE}#3 Bash${NC}
echo '$ < infile.txt cat | bbbb | sort > outfile.txt'
< infile.txt cat | bbbb | sort > outfile.txt 
echo '$ cat outfile.txt'
cat outfile.txt

echo
