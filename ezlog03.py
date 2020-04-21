#!/usr/bin/env python3
""" 
Mission: Support C.R.U.D + S operations upon the EzLog.LOGFILE.
Project: Python 4000, Linux & DevOps (Udemy)
URL:     https://www.udemy.com/course/python-4000-gnu-devops
File:    ezlog.py
Version: 3.0 (Final Release)
"""
import os
import os.path
from datetime import datetime as zdatetime
from email import utils

class EzLog():

    RunDone = None
    Which   = None
    LOGFILE = "./logger.log"

    def __init__(self, message = ''):
        self.LFORMAT = '%Y/%m/%d: %H.%M.%S (LOCAL)'
        self.UFORMAT = '%Y/%m/%d: %H.%M.%S [%z]'
        self._hack(message)

    def _hack(self, message):
        znow = zdatetime.now()
        znow = utils.localtime(znow)
        self.local_date = znow.strftime(format=self.LFORMAT)
        self.message = str(message)

    def __str__(self):
        return self.local_date + "\t" + self.message + "\n"

    def hack(self, message):
        """ Update the time, as well as the message """
        self._hack(message)

    def is_null(self):
        return len(self.message) == 0

    @staticmethod
    def Create(message):
        EzLog.RunDone = None
        entry = EzLog(message)
        with open(EzLog.LOGFILE, "a") as fp:
            if entry.is_null():
                entry.message = "This is a test"
            fp.write(str(entry))
        EzLog.RunDone = "Create"

    @staticmethod
    def List(message):
        try:
            nelem = int(message)
            if nelem < 1:
                print(f"Ignoring {nelem}...")
                return
            with open(EzLog.LOGFILE) as fh:
                for which in range(nelem):
                    line = fh.readline()
                    if not line:
                        break
                    else:
                        print(f"{which+1}.) {line.strip()}")
        except Exception as ex:
            raise ex
        EzLog.RunDone = "List"

    @staticmethod
    def Update(message):
        if EzLog.Which == None:
            EzLog.Which = int(message)
            return
        if EzLog.Which < 1:
            print(f"Ignoring {EzLog.Which}...")
            return
        temp = EzLog.LOGFILE + "~"
        with open(temp, 'w') as fout:
            with open(EzLog.LOGFILE) as fin:
                goal = EzLog.Which - 1
                try:
                    for which in range(EzLog.Which):
                        line = fin.readline()
                        if not line:
                            break; # eof!
                        if which != goal:
                            fout.write(line)
                    if which != goal:
                        raise Exception() # trigger, only
                    fout.write(str(EzLog(message)))
                    try:
                        fout.writelines(fin.readlines())
                    except Exception as ex:
                        pass
                except Exception as ex:
                    fout.close()
                    os.unlink(temp)
                    print(f"Ignored: No line #{EzLog.Which} in {EzLog.LOGFILE}.")
                    return
        os.unlink(EzLog.LOGFILE)
        os.rename(temp, EzLog.LOGFILE)
        EzLog.RunDone = "Update"

    @staticmethod
    def Delete(message):
        temp = EzLog.LOGFILE + "~"
        try:
            nelem = int(message)
            if nelem < 1:
                print(f"Ignoring {nelem}...")
                return
            goal = nelem - 1
            with open(temp, 'w') as fout:
                with open(EzLog.LOGFILE) as fin:
                    try:
                        for which in range(nelem):
                            line = fin.readline()
                            if not line:
                                break; # eof!
                            if which == goal:
                                print("Removing:", line, end='') #stripless
                            else:
                                fout.write(line)
                        if which != goal:
                            raise Exception() # entry not found.
                        fout.writelines(fin.readlines())
                    except Exception as ex:
                        print(f"No log entry #{nelem}.")
                        fout.close()
                        os.unlink(temp)
        except Exception as ex:
            raise ex
        finally:
            if os.path.exists(temp):
                os.unlink(EzLog.LOGFILE)
                os.rename(temp, EzLog.LOGFILE)
        EzLog.RunDone = "Delete"

    @staticmethod
    def Search(message):
        if not message:
            return
        print(f'Searching for "{message}" in {EzLog.LOGFILE} ...')
        with open(EzLog.LOGFILE) as fh:
            for ss, line in enumerate(fh, 1):
                if line.find(message) != -1:
                    print(f"{ss}.) {line}", end='')
        EzLog.RunDone = "Search"

if __name__ == '__main__':
    import argparse
    parser = argparse.ArgumentParser()
    parser.add_argument("-c", "--create",
                        nargs=argparse.REMAINDER,
                        type=EzLog.Create,
                        help='log quoted "message"')
    parser.add_argument("-u", "--update",
                        nargs=argparse.REMAINDER,
                        type=EzLog.Update,
                        help='set list (-l) # to quoted "message"')
    parser.add_argument("-l", "--list",
                        nargs=1,
                        type=EzLog.List,
                        help="list recent messages")
    parser.add_argument("-d", "--delete",
                        nargs=1,
                        type=EzLog.Delete,
                        help='delete list (-l) entry #')
    parser.add_argument("-s", "--search",
                        type=EzLog.Search,
                        help="search log entries")
    parser.parse_args()
    if not EzLog.RunDone:
        parser.print_help()
    else:
        print(f"EzLog: {EzLog.RunDone} Completed.")
