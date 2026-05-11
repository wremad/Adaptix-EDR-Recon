var metadata = {
    name: "EDR Enum",
    description: "Enumerate EDR and AV products using services"
};

var cmd_edr = ax.create_command(
    "edr-enum",
    "Enumerate EDR/AV products",
    "edr-enum"
);

cmd_edr.setPreHook(function(id, cmdline, parsed_json)
{
    let bof_path =
        ax.script_dir() +
        "../build/entry." +
        ax.arch(id) +
        ".o";

    ax.execute_alias(
        id,
        cmdline,
        `execute bof "${bof_path}"`,
        "EDR Enumeration"
    );
});

var group = ax.create_commands_group(
    "EDR Enum",
    [cmd_edr]
);

ax.register_commands_group(
    group,
    ["beacon", "gopher", "kharon"],
    ["windows"],
    []
);
