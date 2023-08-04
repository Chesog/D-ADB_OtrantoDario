create database DIM_DataBaseEdition;
use DIM_DataBaseEdition;

create table Users
(
	UserId integer primary key auto_increment not null,
	UserName varchar(20) not null,
    UserPasword varchar(15) not null
);
create table Weapons
(
    IdWeapon INTEGER PRIMARY KEY AUTO_INCREMENT NOT NULL,
    nameWeapon VARCHAR(30) NOT NULL
);
create table Skills
(
	IdSkill INTEGER PRIMARY KEY AUTO_INCREMENT NOT NULL,
    nameSkill VARCHAR(30) NOT NULL
);
create table Characters
(
    IdCharacter INTEGER PRIMARY KEY AUTO_INCREMENT NOT NULL,
    nameCharacter VARCHAR(30) NOT NULL,
    descriptionCharacter VARCHAR(50) NOT NULL,
    historyCharacter VARCHAR(100) NOT NULL,
    IdSkill INTEGER NOT NULL,
    IdWeapon INTEGER NOT NULL,
    CONSTRAINT FK_IdSkill FOREIGN KEY(IdSkill) REFERENCES Skills(IdSkill),
    CONSTRAINT FK_IdWeapon FOREIGN KEY(IdWeapon) REFERENCES Weapons(IdWeapon)
);
create table Players
(
	IdPlayer INTEGER PRIMARY KEY AUTO_INCREMENT NOT NULL,
	IdUser INTEGER NOT NULL,
    characterSelected INTEGER NOT NULL,
    CONSTRAINT FK_IdUser FOREIGN KEY(IdUser) REFERENCES Users(UserId),
    CONSTRAINT FK_characterSelected FOREIGN KEY(characterSelected) REFERENCES Characters(IdCharacter)
);

insert into Users (UserName,UserPasword)
values ("Pingu","1234");
insert into Users (UserName,UserPasword)
values ("Okami","sakura116");

INSERT INTO Skills(nameSkill)
VALUES
('Fire Ball'),
('Heroic Strike'),
('Rain of Fire'),
('Berserker Stance');

INSERT INTO Weapons(nameWeapon)
VALUES
('Axe'),
('Claymore'),
('Dragonspire'),
('Frostscythe');

INSERT INTO Characters(nameCharacter, descriptionCharacter, historyCharacter, IdSkill, IdWeapon)
VALUES
('Paladin', 'Tank, Healer, Damage', 'Protect the Weak, to Bring Justice to the Unjust',2, 3),
('Death Knight', 'Tank, Damage', 'he called forth a new generation of death knights to join the Ebon Blades cause', 4,2),
('Demon Hunter', 'Tank, Damage', 'Demon hunters, disciples of Illidan Stormrage, uphold a dark legacy',1,4),
('Monk', 'Tank, Healer, Damage', 'Restricted from using weapons, the Monks instead focused on learning weaponless combat',3,1);


DROP DATABASE DIM_DataBaseEdition;