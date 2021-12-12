#/bin/bash

# Header name to change
ORG_HEADER="yyj.h"
TMP_HEADER="tmp.h"
TMP_HEADER2="tmp"

# SETTING VALUE
SOLV_DATE="$1"
MODE="$2"

# DEFINITION VALUE SETTING
definition_setting()
{
    cp -f include/${ORG_HEADER} ${TMP_HEADER}
    cp -f include/${ORG_HEADER} ${ORG_HEADER}

    sed -e 's/#define SOLV_DATE ""/#define SOLV_DATE "'${SOLV_DATE}'"/' ${TMP_HEADER} > ${TMP_HEADER2}
    cp -f ${TMP_HEADER2} ${TMP_HEADER}
    rm ${TMP_HEADER2}

    sed -e 's/#define MODE 0/#define MODE '${MODE}'/' ${TMP_HEADER} > ${TMP_HEADER2}
    cp -f ${TMP_HEADER2} ${TMP_HEADER}
    rm ${TMP_HEADER2}


    mv ${TMP_HEADER} include/${ORG_HEADER}
}

cd source
make clean
cd ..
definition_setting
cd "source"
make 
cd ..
mv ${ORG_HEADER} include/${ORG_HEADER}
mv source/main_exe main_exe
