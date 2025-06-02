module top(G16,G17,G1,G2,G3,G4,G5);
input G1,G2,G3,G4,G5;
output G16,G17;
wire n60,net14,net17,net25,net18;
nor(n60,G2,G5);
nand(net14,G3,G4);
nand(net17,G1,G3);
not(net25,net14);
nand(net18,net14,G2);
nor(G17,n60,net25);
nand(G16,net17,net18);
endmodule
