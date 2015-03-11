# Script for converting menu format in C code for laser harp menu

import fileinput
import re
import string
from operator import itemgetter

menu = []
parents = [-1]

# Process the input file
n = 0
for l in fileinput.input():

  # Remove comments and trailing whitespace
  l = re.sub("\s*(#.*)?$","",l)

  # Ignore blank lines
  if len(l.strip()) == 0:
    continue

  # Split the menu level from the rest
  m = re.match("(\s*)(.*)", l)
  level = len(m.group(1)) / 2
  text = m.group(2).split(",")

  # Have we added a new menu level
  if len(parents) < level+1:
    parents.append(n-1)
    last_level = level
    menu[-1][2] = n

  # Truncate other levels off
  while len(parents) > level+1:
    menu.append([n, parents[-1], -3, -1, ["Back"]]);
    n = n + 1
    parents.pop()

  # Store (number, parent number, selection number, ctrl, text info)
  menu.append([n, parents[-1], 0, -1, text]);
  n = n + 1

# Truncate other levels off
while len(parents) > level+1:
  menu.append([n, parents[-1], -3, 0, ["Back"] ]);
  n = n + 1
  parents.pop()

# Print out the select definitions
print "/* Control/action definitions */"
n_controls = 0
n_actions = 0
controls = []
actions = []
for m in menu:
  if len(m[4]) > 1 and m[4][1].startswith("C"):
    if len(m[4]) < 4:
      print "Error on line \""+ ",".join(m[4]) + "\""
      quit()
    m[3] = n_controls
    m[2] = -1
    controls.append( [ n_controls, m[4][2], m[4][1][1:], m[4][3]] )
    n_controls = n_controls + 1
  if len(m[4]) > 1 and m[4][1].startswith("A"):
    m[3] = n_actions
    m[2] = -2
    actions.append( [n_actions, m[4][2]] )
    n_actions = n_actions + 1

# Print out the control data array
print "/* Array of control values */"
print "char controls[" + str(n_controls) + "];\n"

# Print the control names
for c in controls:
  print "#define CTRL_"+c[1].upper().ljust(28)+str(c[0])
print "\n"

# Print the action names
for a in actions:
  print "#define ACTION_"+a[1].upper().ljust(26)+str(a[0])
print "\n"

# Print out the factory default values
print "/* Array of default control values */"
print "const char control_defaults["+str(n_controls)+"] = {"
for c in controls:
  print "  "+c[2]+ ","
print "};\n"

# Print out the control types
print "/* Array of default control values */"
print "const char control_types["+str(n_controls)+"] = {"
for c in controls:
  print "  "+c[3]+ ","
print "};\n"

# Sort items into sibling groups
menu.sort(key=itemgetter(1))

# Extract the reordered list positions
neworder = [m[0] for m in menu]

# A list for the sorted menu
sorted_menu = []

# Now print main menu
n = 0
p = -2
s = 0
e = 0
ud = 0
ctrl_type = 0
print "/* ------------------ The menu structure ----------------- */"

for m in menu:
  # Find the 'up/down' value
  if m[1] != p:
    p = m[1]
    s = n
    e = n + len([mm for mm in menu if mm[1] == p]) - 1
    ud = e
  elif n == e:
    ud = s
  else:
    ud = -1

  # Find the 'select' value
  sel = m[2]
  if sel >= 0:
    sel = neworder.index(sel)

  # Find the control value
  ctrl = m[3] 

  # Find the control type
  if sel == -1:
    ctrl_type = m[4][3]
  else:
    ctrl_type = -1

  # Print the menu entry information
  print "/*  "+str(n).ljust(5)+": "+str(ud).rjust(6)+" | "+str(sel).rjust(6)+" | "+str(ctrl).rjust(6)+" | "+m[4][0].ljust(20)+" */"
  sorted_menu.append( [ ud, sel, ctrl, ctrl_type, m[4][0] ] );
  n = n + 1

print "/* ------------------------------------------------------- */\n"

# Print the menu direction
print "const char menu_dir[] = {"
for m in sorted_menu:
  print "  " + str(m[0]) + ",";
print "};\n"

# Print the menu selection
print "const char menu_sel[] = {"
for m in sorted_menu:
  print "  " + str(m[1]) + ",";
print "};\n"

# Print the menu control
print "const char menu_ctrl[] = {"
for m in sorted_menu:
  print "  " + str(m[2]) + ",";
print "};\n"

# Print the menu control types
print "const char menu_ctrl_types[] = {"
for m in sorted_menu:
  print "  " + str(m[3]) + ",";
print "};\n"

# Print the menu strings
print "const char* menu_str[] = {"
for m in sorted_menu:
  print "  \"" + m[4] + "\",";
print "};\n"


# Now print out the template control up/down, display and update functions
print "/* -------------------------- TEMPLATE FUNCTIONS -------------------------------*/\n\n\n"

for c in controls:
  name = string.capwords(c[1],"_").replace("_","")
  print "static void updateControl"+name+"() {\n};\n"

print "static void (*updateControlFns["+str(n_controls)+"])() = {"
for c in controls:
  name = string.capwords(c[1],"_").replace("_","")
  print "  updateControl"+name+","
print "};\n\n"

print "static void updateControl(unsigned int c) {"
print "  updateControlFns[c]();"
print "};\n\n"

print "static void updateAllControls() {"
print "  unsigned int c;"
print "  for (c=0; c<"+str(n_controls)+"; c++) {"
print "    updateControl(c);"
print "  }"
print "}\n\n"

print "/* -------------------------------------------------------------------------------*/\n\n"
