module loop (A, B, C, P);
    input A;
    input B;
    input C;
    output P;

    wire w1, w2, w3;

    and (w1, A, B);
    and (w2, C, w3);
    and (w3, w1, w2);
    and (P, w1, w2);
endmodule

// loop, 3 input, 1 output