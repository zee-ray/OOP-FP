module Larger (A, B, C, P, Q);
    input A;
    input B;
    input C;
    output P;
    output Q;

    wire w1, w2, w3, w4, w5, w6, w7, w8, w9;

    nor (P, w5, w9);
    and (w9, w4, w8);
    and (w1, A, B);
    not (w2, w1);
    buf (w3, w2);
    or  (w4, w3, w6);
    buf (w5, w4);
    nand (w6, B, C);
    not (w7, w6);
    nxor (w8, C, w7);
    not (Q, w8);
endmodule

// larger, 3 input, 2 output