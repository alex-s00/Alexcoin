 #!/usr/bin/env bash

 # Execute this file to install the alex cli tools into your path on OS X

 CURRENT_LOC="$( cd "$(dirname "$0")" ; pwd -P )"
 LOCATION=${CURRENT_LOC%Alex-Qt.app*}

 # Ensure that the directory to symlink to exists
 sudo mkdir -p /usr/local/bin

 # Create symlinks to the cli tools
 sudo ln -s ${LOCATION}/Alex-Qt.app/Contents/MacOS/alexd /usr/local/bin/alexd
 sudo ln -s ${LOCATION}/Alex-Qt.app/Contents/MacOS/alex-cli /usr/local/bin/alex-cli
