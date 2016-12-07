#!/usr/bin/env bash

# Clean up previous operation results.
if [ -s tmp/scenarios ]
    then
        rm -rf tmp/scenarios
fi
mkdir tmp/scenarios

echo -e "| Module | Number of scenarios |\n| --- | --- | " > tmp/scenarios/reports.md


function check_module {
    module=$1
    type=$2
    ./tests/behat -c tests/behat.yml --format=pretty --dry-run --tags="@$module" | grep "Scenario:\|Scenario Outline:" > test.tmp
    if [ -s test.tmp ]
        then
            sed "
s/  Scenario://g
s/  Scenario Outline://g
s/# features/| tests\/features/g
" test.tmp > test2.tmp;
            echo -e "BEHAT scenarios related to __${module}__.\n\n| Scenario | Location of test |\n| --- | --- |\n$(cat test2.tmp) " > tmp/scenarios/${module}.md
            scenario_count=$(echo -e "$(wc -l < test.tmp)" | sed -e 's/^[ \t]*//')
            echo -e "| ${type}/${module} | ${scenario_count} |" >> tmp/scenarios/reports.md
            rm test2.tmp
            printf "${type}/\e[1m${module}\e[0m done: \e[32m${scenario_count} scenario(s) found\e[0m\n"
        else
            echo -e "| __${type}/${module}__ | __0__ |" >> tmp/scenarios/reports.md
            printf "${type}/\e[1m${module}\e[0m done: \e[31m0 scenarios found\e[0m\n"
    fi
    rm test.tmp
}

LIBPATH=lib
for path in "${LIBPATH}"/*/ ; do
        type=${path#"${LIBPATH}/"}
        type=${type%"/"}
        if [ "$type" == "features" ] || [ "$type" == "modules" ] ; then
            for d in "${path}"/*/ ; do
                feature=${d#"${path}/"}
                feature=${feature%"/"}
                check_module ${feature} ${type}
            done
        fi
done
