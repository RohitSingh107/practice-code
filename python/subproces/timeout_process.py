import subprocess

proc = subprocess.Popen(['ping', '-c 5', 'google.com'],
                        stdout=subprocess.PIPE,
                        stderr=subprocess.STDOUT)

try:
    outs, _ = proc.communicate(timeout=10)
    print('RETURN CODE', proc.returncode)
    print(outs.decode('utf-8'))
except subprocess.TimeoutExpired:
    print('subprocess did not terminate in time')	
    proc.terminate()	