# dekofile (DF) 🚀
> **Current Version: 2.0 (System Mode + Localhost Bridge)**

A minimalist, rootless build automation tool for people who hate bloat. Build anything, anywhere—from Termux to Cloud VMs.

### 🔥 [Your information is NOT saved, relax, have a coffee, this process may take a while.]

## Why DF?
- **Rootless by design**: No docker daemon, no sudo requirements (unless you want to).
- **Auto-dependency**: If a tool is missing, DF fetches it.
- **Microscopic**: The entire engine is just a few KB.
- **Cloud-Ready**: Push your local context to HFS, AWS, or Oracle with one command.

## Syntax
Create a file named `dekofile`:

```dockerfile
IMPORT (package_name) ROOTLESS
RUN ./DF IN: (subfolders/files)
G++ (files) -o (output)
EnD
(This is a fcking example,make your own)

How to use
Run the engine on your file:

Bash
DF dekofile

Cloud Push
Push your build context to a remote VM or Hugging Face Space:

Bash
Deko F-- push [URL] -- login [PASSWORD] && [USER]
Safety Warning
DF executes raw bash commands. If you put sudo rm -rf / in your dekofile and you have root, it’s your problem

=======================================================================================================================================
  		   FakeADB
Now,this tool can execute root commands whitout root! You need to add in your deko file:


```dockerfile
IMPORT F_A
```

The rest of your trash code

im NOT responsable for damages on your device after you write 'sudo rm -rf /' if you make this,how are you reading this? on a potato?

so,is this,if you want to report a bug... wait,i dont have discord

cya! :D

(go write now,stop reading this shit)

=============================================================================================
