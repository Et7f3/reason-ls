exception Missing_env_var(string);

let handle_errors = fn =>
  try(fn()) {
  | Missing_env_var(name) =>
    Stdio.prerr_endline(
      "Ooops, it seems you don't have an environment variable named \""
      ++ name
      ++ "\". I need it to work!",
    );

    Caml.exit(201);
  | _ as exn =>
    Stdio.prerr_endline(
      "Ooops, an unknown error occured. You can file a bug reports at https://github.com/danielo515/reason-ls/issues.\n"
      ++ "Here is the stack trace in case it helps:\n",
    );

    raise(exn);
  };

type error = {
  doc: string,
  exit_code: int,
};

let all = () => [
  {doc: "on missing required environment variable.", exit_code: 201},
];