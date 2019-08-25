create table cpp.test
(
    id      bigint auto_increment  not null,
    created datetime default now() not null,
    updated datetime               not null,
    version integer,
    name    varchar(255) unique,
    primary key (id),
    index (name),
    index (id)
)
    engine = InnoDB;

insert into cpp.test (created, updated, version, name)
values (now(), now(), 0, 'test');
