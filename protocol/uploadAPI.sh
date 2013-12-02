#! /bin/bash
wget https://github.com/lamber-k/Babel-Protocol-API/archive/master.zip &> /dev/null &&
unzip master.zip  &> /dev/null &&
rsync -a Babel-Protocol-API-master/API/ ./API/ && 
rsync -a Babel-Protocol-API-master/doc/ ./doc/ &&
rm -rf master.zip Babel-Protocol-API-master  &> /dev/null && echo "DONE !" || echo "FAIL"
