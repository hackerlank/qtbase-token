TEMPLATE = subdirs

SUBDIRS = subtest test warnings maxwarnings cmptest globaldata skip \
          strcmp expectfail sleep fetchbogus crashes multiexec failinit failinitdata \
          skipinit skipinitdata datetime singleskip assert differentexec \
          exceptionthrow datatable commandlinedata \
          benchlibwalltime benchlibcallgrind benchlibeventcounter benchlibtickcounter \
          benchliboptions xunit badxml longstring float printdatatags \
          printdatatagswithglobaltags findtestdata

INSTALLS =

QT = core


CONFIG += parallel_test
