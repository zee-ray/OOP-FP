module huge (A, B, C, D, E, F, G, H, I, J, P, Q, R, S);

input A;
input B;
input C;
input D;
input E;
input F;
input G;
input H;
input I;
input J;

output P;
output Q;
output R;
output S;

wire w1, w2, w3, w4, w5, w6, w7, w8, w9, w10,
     w11, w12, w13, w14, w15, w16, w17, w18, w19, w20,
     w21, w22, w23, w24, w25, w26, w27, w28, w29, w30,
     w31, w32, w33, w34, w35, w36, w37, w38, w39, w40,
     w41, w42, w43, w44, w45, w46;

and  (w1, A, 1'b1);
or   (w2, C, 1'b0);
xor  (w3, w1, w2);
not  (w4, E);
nand (w5, F, G);
nor  (w6, H, I);
buf  (w7, w6);
and  (w8, w4, w5);
or   (w9, w3, w8);
nand (w10, w7, w9);

xor  (w11, A, w10);
not  (w12, w11);
buf  (w13, J);
and  (w14, w13, w12);
xor  (w15, w14, 1'b1);
nor  (w16, w15, w3);
nand (w17, w8, w16);
or   (w18, w17, w6);
not  (w19, w18);
and  (w20, w19, w14);

nand (w21, w20, w2);
buf  (w22, w21);
xor  (w23, w22, w5);
or   (w24, w23, w7);
not  (w25, w24);
nor  (w26, w25, w16);
and  (w27, w26, w18);
xor  (w28, w27, 1'b0);
nand (w29, w28, w19);
not  (w30, w29);

buf  (w31, w30);
and  (w32, w31, w10);
xor  (w33, w32, w6);
nor  (w34, w33, w22);
not  (w35, w34);
nand (w36, w35, w1);
or   (w37, w36, 1'b0);
not  (w38, w37);
buf  (w39, w38);
and  (w40, w39, w24);

xor  (w41, w40, w12);
not  (w42, w41);
nand (w43, w42, w25);
nor  (w44, w43, 1'b1);
xor  (w45, w44, w8);
not  (w46, w45);

nor  (P, w5, w20);
or   (Q, w30, w15);
and  (R, w39, w12);
xor  (S, w46, w1);

endmodule
