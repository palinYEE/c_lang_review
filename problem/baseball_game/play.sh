#/bin/bash

# Header name to change
ORG_HEADER="problem.h"
TMP_HEADER="tmp.h"
TMP_HEADER2="tmp"

# SETTING VALUE
SOLV_DATE="$1"
PROB_content="숫자 야구 게임"
EX_input="answer = [1,2,3], user = [1,3,0]"
EX_output="strike: 1, ball: 1"

# DEFINITION VALUE SETTING
definition_setting()
{
    cp -f include/${ORG_HEADER} ${TMP_HEADER}
    cp -f include/${ORG_HEADER} ${ORG_HEADER}

    sed -e 's/#define SOLV_DATE ""/#define SOLV_DATE "'${SOLV_DATE}'"/' ${TMP_HEADER} > ${TMP_HEADER2}
    cp -f ${TMP_HEADER2} ${TMP_HEADER}
    rm ${TMP_HEADER2}

    sed -e 's/PROB_content ""/PROB_content "'"${PROB_content}"'"/' ${TMP_HEADER} > ${TMP_HEADER2}
    cp -f ${TMP_HEADER2} ${TMP_HEADER}
    rm ${TMP_HEADER2}

    sed -e 's/EX_input ""/EX_input "'"${EX_input}"'"/' ${TMP_HEADER} > ${TMP_HEADER2}
    cp -f ${TMP_HEADER2} ${TMP_HEADER}
    rm ${TMP_HEADER2}

    sed -e 's/EX_output ""/EX_output "'"${EX_output}"'"/' ${TMP_HEADER} > ${TMP_HEADER2}
    cp -f ${TMP_HEADER2} ${TMP_HEADER}
    rm ${TMP_HEADER2}

    mv ${TMP_HEADER} include/${ORG_HEADER}
}

definition_setting
cd "source"
make 
cd ..
mv ${ORG_HEADER} include/${ORG_HEADER}