from pathlib import Path
from datetime import datetime, timezone
import argparse, json, subprocess, time

parser = argparse.ArgumentParser()
parser.add_argument('--compiler', default='g++')
args = parser.parse_args()
root = Path(__file__).resolve().parent
build = root/'build'
build.mkdir(exist_ok=True)
cases = json.loads((root/'TEST_CASES.json').read_text())
records = []
for item in cases:
    source = root/item['slug']/'solution.cpp'
    record = dict(problem=item['title'],function_checks=item['checks'],stdin_stdout_cases=len(item['cli']))
    for local in (True, False):
        exe = build/(item['slug']+('-local' if local else '-judge')+'.exe')
        command = [args.compiler,'-std=c++11','-Wall','-Wextra','-pedantic']
        if local: command.append('-DLOCAL_TEST')
        compiled = subprocess.run(command+[str(source),'-o',str(exe)],capture_output=True,text=True,timeout=30)
        if compiled.returncode or compiled.stderr: raise RuntimeError(compiled.stderr)
        if local:
            run = subprocess.run([str(exe)],capture_output=True,text=True,timeout=10)
            if run.returncode: raise RuntimeError(run.stderr)
            print(run.stdout.strip(),flush=True)
        else:
            for stdin, expected in item['cli']:
                run = subprocess.run([str(exe)],input=stdin,capture_output=True,text=True,timeout=10)
                if run.returncode or run.stdout != expected:
                    raise RuntimeError(f"{item['title']}: got {run.stdout!r}, expected {expected!r}; {run.stderr}")
            print(f"PASS {item['title']}: {len(item['cli'])} stdin/stdout cases",flush=True)
    record['status']='Passed'
    records.append(record)
(root/'TEST_RESULTS.json').write_text(json.dumps({'checked_utc':datetime.now(timezone.utc).isoformat(),'results':records},indent=2),encoding='utf-8')
print(f'All {len(records)} programs passed in both build modes.',flush=True)
