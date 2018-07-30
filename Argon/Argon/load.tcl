# Usage: vmd -e load.tcl
# temp_pos is the directory that you store all your coordinate files.
# The files are named file_$index.xyz (from 1 to tmax)

cd C:/Users/shuva/OneDrive/Documents/GitHub/Vistas-of-Advanced-Computing/Argon/Argon

#Ex. Size Box = 6
# Box from (0,0,0) to (L,L,L)---> L=6 and or=0
# Box from (-L/2,-L/2,-L/2) to (L/2,L/2,L/2)---> L=3 and or=-3 
set L 3
set or -3

mol new ATOM125.xyz
# This is to load all the frames (snapshots)


cd ..


## Draw the box (Periodic Boundary Conditions)
#pbc set "$L $L $L" -all
#pbc box -color blue -style tubes -width 2

#Draw lines for Box (instead of pbc)
draw color 0
#draw materials off

draw line "$or $or $or" "$or $or $L" width 2 style solid 
draw line "$or $or $or" "$or $L $or" width 2 style solid 
draw line "$or $or $or" "$L $or $or" width 2 style solid 

draw line "$L $or $or" "$L $L $or" width 2 style solid 
draw line "$L $or $or" "$L $or $L" width 2 style solid 

draw line "$or $L $or" "$L $L $or" width 2 style solid
draw line "$or $L $or" "$or $L $L" width 2 style solid

draw line "$or $or $L" "$L $or $L" width 2 style solid
draw line "$or $or $L" "$or $L $L" width 2 style solid

draw line "$L $L $or" "$L $L $L" width 2 style solid 
draw line "$L $or $L" "$L $L $L" width 2 style solid 
draw line "$or $L $L" "$L $L $L" width 2 style solid 


#draw materials on
#define a new, very transparent material 'Glass'
#material add Glass
#material change ambient		Glass	0.00
#material change specular	Glass	0.50
#material change diffuse		Glass	0.65
#material change shininess	Glass	0.53
#material change	opacity		Glass	0.1

#draw material Glass
draw color 23
draw triangle "$or $or $or" "$L $or $or" "$or $L $or"
draw triangle "$L $L $or" "$L $or $or" "$or $L $or"

#mol delete all
mol delrep 0 top
mol selection {all and not serial 63}
mol representation VDW 0.1 50
mol color ColorID 7
mol addrep 0 
mol delrep 1 top
mol selection {serial 63}
mol representation VDW 0.1 50
mol color ColorID 1
mol addrep top
