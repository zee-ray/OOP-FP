module multi (A, B, C, P);
    input A;
    input B;
    output C;
    output P;

    wire w1, w2;

    or (w1, A, B);
    not (w2, 1'b1);
    or (P, w2, C);
    nand (C, P, A);
    xor (C,1'b0, w1);
endmodule

// multi-driven(C), 2 input, 2 output