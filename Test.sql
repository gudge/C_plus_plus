DROP SCHEMA IF EXISTS s CASCADE;  
CREATE SCHEMA s;

CREATE TABLE s.cities (
    name            text,
    population      real,
    altitude        int
);

CREATE TABLE s.capitals (
    state           char(2)
) INHERITS (s.cities);

INSERT INTO s.capitals(state) values ('ab');

-- SELECT * FROM s.capitals;
SELECT * FROM s.cities;

DROP SCHEMA IF EXISTS s CASCADE;  