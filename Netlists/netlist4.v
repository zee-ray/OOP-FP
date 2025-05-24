module larger (A, B, C, P);
    input A;
    input B;
    input C;
    output P;

    wire w1, w2;

    or (w1, A, B);
    not (w2, 1'b1);
    or (P, w2, C);
endmodule